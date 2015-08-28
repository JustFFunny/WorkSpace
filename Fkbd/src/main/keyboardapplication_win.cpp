#include <QWidget>
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <winuser.h>

#include "keyboardapplication.h"



INPUT genKey(bool pressed, ushort key,bool translated)
{
   // if (!translated)
     //   key = VkKeyScan(key);

    INPUT input;
    memset(&input, 0, sizeof(INPUT));
    input.type = INPUT_KEYBOARD;

    input.ki.wVk = key;
    if (pressed)
        input.ki.dwFlags = 0;
    else
        input.ki.dwFlags = KEYEVENTF_KEYUP;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    return input;
}// genKey


KeyboardApplication::KeyboardApplication(int &argc, char **argv):QApplication(argc,argv)
{
    m_keyWidget = NULL;
    m_focusWindow = 0;
    init();
}

bool KeyboardApplication::winEventFilter(MSG * msg, long * result)
{
  if (m_keyWidget)
  {
    HWND keyWnd = m_keyWidget->winId();
    HWND forWnd = GetForegroundWindow();
    if( IsWindow(forWnd) ) {
      if( forWnd != keyWnd ) {
        if(m_focusWindow != forWnd){
           if( IsWindow(m_focusWindow) ){
                        AttachThreadInput(
                                GetWindowThreadProcessId(keyWnd,NULL),
                                GetWindowThreadProcessId(m_focusWindow,NULL),
                                FALSE);
           }
              m_focusWindow = forWnd;
              AttachThreadInput(
                            GetWindowThreadProcessId(keyWnd,NULL),
                            GetWindowThreadProcessId(m_focusWindow,NULL),
                            TRUE);
        }// m_focusWindow
      }// wnd != m_keyWidget->Wid()
    }// IsWindow(m_focusWindow)
  }// m_keyWidget


  switch(msg->message)
  {

  case WM_MOUSEACTIVATE:
  {
      clearFocus();
      *result = MA_NOACTIVATE;
      return true;
    }
  default:
     return QApplication::winEventFilter(msg,result);
  }// switch
}//winEventFilter


void KeyboardApplication::clearFocus()
{
    if(IsWindow(m_focusWindow)) {
       HWND wnd = ::GetForegroundWindow();
       if(IsWindow(wnd)) {
          if(wnd == m_focusWindow)
             { return; }
       }

       SetForegroundWindow(m_focusWindow);
       SetFocus(m_focusWindow);
    }
}


void KeyboardApplication::setKeyboardWidget(QWidget * widget)
{
    m_keyWidget = widget;
}


void KeyboardApplication::typeText( const QString & msg)
{
    QString text = resolve(msg);
    bool translated = (text!=msg);

    INPUT in[8];


    for (int i=0; i < text.length() ; i++)
    {
        int index =0;
        SHORT key = text[i].unicode();
        if (!translated)
        {
            key = VkKeyScan(key);
            if (key & 0x0100)
                in[index++] = genKey(true,VK_SHIFT,true);
            if (key & 0x0200)
                in[index++] = genKey(true,VK_CONTROL,true);
            if (key & 0x0400)
                in[index++] = genKey(true,VK_MENU,true);
        }

        in[index++] = genKey(true,key & 0xff,translated);
        in[index++] = genKey(false,key & 0xff,translated);

        if (!translated)
        {
            SHORT key = VkKeyScan(text[i].unicode());
            if (key & 0x0100)
                in[index++] = genKey(false,VK_SHIFT,true);
            if (key & 0x0200)
                in[index++] = genKey(false,VK_CONTROL,true);
            if (key & 0x0400)
                in[index++] = genKey(false,VK_MENU,true);
        }
        //clearFocus();
        SendInput(index,in,sizeof(INPUT));
      //   qDebug("Sending %d keys /n\n--------------------",index);
    }// text[i]
}//typeText

void KeyboardApplication::keysDown(const QString & keys)
{

    QString text = resolve(keys);
    bool translated = (text!=keys);
    //qDebug("Keys down:%s, %d",qPrintable(keys),(int)translated);
    INPUT input;
    for (int i=0;i<text.length();i++)
    {
        input = genKey(true,text[i].unicode(),translated);
        //clearFocus();
        SendInput(1,&input,sizeof(INPUT));
    }
}

void KeyboardApplication::keysUp(const QString & keys)
{
    QString text = resolve(keys);
    bool translated = (text!=keys);

    INPUT input;
    for (int i=0;i<text.length();i++)
    {
        input = genKey(false,text[i].unicode(),translated);
        //clearFocus();
        SendInput(1,&input,sizeof(INPUT));
    }
}

QString KeyboardApplication::resolve(const QString & text )
{
   if (m_keys.contains(text))\
   {
      // qDebug("Does contain %s",qPrintable(text));
       return m_keys[text];
   }
   return text;
}

void KeyboardApplication::init()
{
    m_keys["Esc"] = "\x1b";
    m_keys["F1"] = "\x70";
    m_keys["F2"] = "\x71";
    m_keys["F3"] = "\x72";
    m_keys["F4"] = "\x73";
    m_keys["F5"] = "\x74";
    m_keys["F6"] = "\x75";
    m_keys["F7"] = "\x76";
    m_keys["F8"] = "\x77";
    m_keys["F9"] = "\x78";
    m_keys["F10"] = "\x79";
    m_keys["F11"] = "\x7a";
    m_keys["F12"] = "\x7b";

    m_keys["Ins"] = "\x2D";
    m_keys["Del"] = "\x2E";
    m_keys["`"] = "\xC0";  // ~ tylda
    m_keys["Backspace"] = "\x08";
    m_keys["-"] = "\xbd"; // - _
    m_keys["="] = "\xbb"; // = +
    m_keys["Tab"] = "\x09";

    m_keys["Caps Lock"] = "\x14";
    m_keys["Enter"] = "\x0d";

    m_keys["Shift"] = "\x10";

    m_keys["up_key"] = "\x26";

    m_keys["Ctrl"] = "\x11";
    m_keys["Alt"] = "\x12";
    m_keys["Space"] = "\x20";
    m_keys["AltGr"] = "\x11\x12";

    m_keys["left_key"] = "\x25";
    m_keys["down_key"] = "\x28";
    m_keys["right_key"] = "\x27";

}// init

