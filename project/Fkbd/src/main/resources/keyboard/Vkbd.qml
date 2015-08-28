import Qt 4.7

Rectangle { id: vkbd;

   state: 'normal'

   signal textTyped(string str)
   signal keyPressed(string str)
   signal keyReleased(string str)

   function minimize()  { store(); keyboard.state = 0; state = 'minimized'  }
   function maximize()  { store(); keyboard.state = 2; state = 'maximize' }
   function restore()   { store(); keyboard.state = 1; state = 'normal' ; flip.state = '' }

   function toggle()
   {
        flip.state = 'back'
   }

   function typeText(str) { keyboard.typeText(str) ; if (str!="Tab")  vkbd.releaseKeys() ; vkbd.textTyped(str) }
   function keyDown(key)  { keyboard.keyDown(key) ; vkbd.keyPressed(key)  }
   function keyUp(key)    { keyboard.keyUp(key)   ; vkbd.keyReleased(key) }
   function close()       { keyboard.close();      }
   function setPressed(i) { keyboard.setPressed(i) }

   function incOpacity() { if (vkbd.lastOpacity < 1) vkbd.lastOpacity+=0.1 ; vkbd.opacity = vkbd.lastOpacity }
   function decOpacity() { if (vkbd.lastOpacity > 0.3) vkbd.lastOpacity-=0.1 ; vkbd.opacity = vkbd.lastOpacity }
   function calcMaxY(height) { if (lastY + height > keyboard.maxHeight )  return keyboard.maxHeight - height;  return lastY }
   function changeLayout() { store() ;  kbd.changeLayout() }


   function store() {
                           //console.log("Moving to lastX:"+lastX+" lastY:"+lastY+" from:"+state);
                           if (state == 'normal') { vkbd.lastX = keyboard.x ; vkbd.lastY = keyboard.y }
                           if (state == 'minimized') { vkbd.lastYMinimized = keyboard.y }
                    }


   function switchState()
   {
     if (false == kbdButton.toggled )
        minimize();
     else
        restore();
   }//switchState

   function init()
   {
      //kbdButton.toggled = false;
      //minimized();
      kbdButton.toggled = true;
      restore();
   }

   Component.onCompleted : init();

   property int maxWidth : 10;
   property int maxHeight : 10;
   property real lastOpacity: 1
   property int lastX : (keyboard.maxWidth - kbd.width  )/2;
   property int lastY : (keyboard.maxHeight - kbd.height )/2 + navibuttons.height;
   property int lastYMinimized : lastY

   signal releaseKeys;

   smooth: true;
   radius: 8;
   border.color: "#b0b0b0";
   border.width: 0;

   color: "#0f0f0f00"
  
   MouseArea
   {
      anchors.fill : parent;
      onPressed : {  setPressed(true);  }
      onReleased : { setPressed(false); }
   }
   Flip
   {
     id: flip

     width: layout.width
     height:  layout.height
     //width: parent.width
     //height: parent.height


     front:
     Column { id: layout;
                     x: 7;
                     y: 5;
               spacing: 6;

               Row { id: navibuttons
                   spacing: 6
                   width: kbd.width - 4
                   //anchors.horizontalCenter:parent.horizontalCenter

                   NaviButton { id: kbdButton    ;  icon: "pic/layout2.png" ; toggable : true ; width: 50 }

                   Row{
                       anchors.centerIn:parent
                       spacing: parent.spacing
                       NaviButton { id: plusOpacity ; text: "+" ; font.bold: true ; font.pointSize: 12 ; width: 35 }
                       NaviButton { id: layoutButton ; icon:"pic/layout.png" ; width: 80 ; toggable: true }
                       NaviButton { id: minusOpacity ; text: "-" ;font.bold: true ; font.pointSize: 12 ; width: 35}
                   }
                   NaviButton { id: progsButton  ;  icon:"pic/go-next.png" ; text: "Menu" ; /* width: 45  ; */  anchors.right: navibuttons.right}
                   } // navibuttons

                   Keyboard {id:kbd }
             }// column layout

       back:
       Item {
             id: backLayout
             width: layout.width ; height: layout.height
             NaviButton { id: backButton  ;  icon: "pic/go-previous.png" ; /* width: 45 ;*/ text: "Back" ; y: 7 ; x: backLayout.width - width + 4; }
             NaviButton { id: closeButton  ;  icon: "pic/application-exit.png" ; /*width: 45 ;*/ text: "Close";  y: 7 ; x: 7 }
             LaunchTab { id: lanuchTab; width: backLayout.width }

             Connections { target: backButton  ; onClicked: vkbd.restore()   }
             Connections { target: closeButton ; onClicked: keyboard.close() }
            }
   } // flip

   Connections { target: layoutButton ; onClicked: vkbd.changeLayout() }
   Connections { target: progsButton  ; onClicked: vkbd.toggle()       }
   Connections { target: kbdButton    ; onClicked: vkbd.switchState()  }
   Connections { target: plusOpacity  ; onClicked: vkbd.incOpacity()   }
   Connections { target: minusOpacity ; onClicked: vkbd.decOpacity()   }
   Connections { target: vkbd         ; onReleaseKeys: kbd.releaseKeys() }

  states:
      [
       State{
              name: "minimized" ;

              PropertyChanges { target: vkbd ;
                                width: kbdButton.width + layout.x  * 2;
                                height: kbdButton.height + layout.y * 2 }
              PropertyChanges { target: keyboard ;
                                width: kbdButton.width + layout.x  * 2;
                                height: kbdButton.height + layout.y *2  ;
                                x : keyboard.maxWidth - (kbdButton.width + layout.x  * 2)
                                y : vkbd.lastYMinimized ;
                              }


            },
       State{
              name: "normal" ;
               PropertyChanges {
                                  target: vkbd ; width : kbd.width + 10  ; height: kbd.height + navibuttons.height + 10 + 5
                                  opacity: lastOpacity
                              }
              PropertyChanges {
                                target: keyboard ;
                                width : kbd.width + 10  ; height: kbd.height + navibuttons.height + 10 + 5
                                x : lastX ; y : calcMaxY(kbd.height + navibuttons.height + 10 + 5);
                              }
            }

      ]

   transitions:[
   Transition
   {
       NumberAnimation { properties: "x,y,width,height"; easing.type: Easing.InOutQuad ; duration: 500 }
       NumberAnimation { properties: "opacity"; easing.type: Easing.InOutQuad;  duration: 250 }
   }

   ] // transitions

}// vkbd
