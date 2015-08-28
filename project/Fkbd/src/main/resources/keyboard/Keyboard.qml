import Qt 4.7

Item {

   id: vkeyboard ;
  // scale: 0.75
   smooth: true
   property int spacing : 4
   property color fun_up : "#313131"
   property color fun_down : "#414141"

   property color key_up   : "#979797"
   property color key_down : "#A7A7A7"

   property color digi_up : "#C1C1B1"
   property color digi_down : "#D1D1C1"

   state : "Layout1";

   function changeLayout()
   {
     /*
     if (vkeyboard.state == 'Layout2')
     {
        state = 'Layout3'
        return;
     }
     */
     vkeyboard.state = ( vkeyboard.state == 'Layout1' ? 'Layout2' : 'Layout1' ) ;
     numericPad.state  = ( numericPad.state == 'Layout1' ? 'Layout2' : 'Layout1' ) ;
     //if (vkeyboard.state == 'Layout3' )
      //  vkeyboard.state = 'Layout1'
   }

   function releaseKeys()
   {
     if (shiftKey.toggled) shiftKey.release();
     if (ctrlKey.toggled) ctrlKey.release();
     if (altKey.toggled) altKey.release();
     if (altgrKey.toggled) altgrKey.release();
   }
     Row { // Function keys
            id: functionKeys;
            spacing: vkeyboard.spacing; // space between keys
            StdButton { text: "Esc" ; id: esc }
            StdButton { text2: "F1" ; key:"F1" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F2" ; key:"F2" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F3" ; key:"F3" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F4" ; key:"F4" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F5" ; key:"F5" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F6" ; key:"F6" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F7" ; key:"F7" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F8" ; key:"F8" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F9" ; key:"F9" ; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F10"; key:"F10"; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F11"; key:"F11"; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
            StdButton { text2: "F12"; key:"F12"; up : vkeyboard.fun_up ; down : vkeyboard.fun_down}
        } // Function keys


       Row { // insDel
              id: insDel;
              spacing: vkeyboard.spacing;
              StdButton { x:2; text2: "Ins" ; key: "Ins"  }
              StdButton { text2: "Del" ; key: "Del"  }
           }

       StdButton { id : tylda ; text: "`";  text2: "~" }


        StdButton { id: backspace;
                    text: "Backspace";
                    x : (esc.width+vkeyboard.spacing)*13;
                    text2: " " ;
                    width: esc.width * 2 + vkeyboard.spacing }

                    Rectangle
                        { // numericPad
                        id: numericPad ;
                        y: (esc.height+vkeyboard.spacing) ;

                        state : "Layout1" ;

                        Row // _123
                        {
                            id: _123;
                            spacing: vkeyboard.spacing;
                            StdButton { text: "1";  text2: "!" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "2";  text2: "@" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "3";  text2: "#" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                        }
                        Row // _456
                        {
                            id: _456;
                            spacing: vkeyboard.spacing;
                            x: (esc.height+vkeyboard.spacing) * 3 + spacing;
                            StdButton { text: "4";  text2: "$" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "5";  text2: "%" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "6";  text2: "^" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                        }
                        Row // _789
                        {
                            id: _789;
                            spacing: vkeyboard.spacing;
                            StdButton { text: "7";  text2: "&" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "8";  text2: "*" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "9";  text2: "(" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                        }
                        Row // _0
                        {
                            id: _0;
                            spacing: vkeyboard.spacing;
                            StdButton { text: "0";  text2: ")" ; up : vkeyboard.digi_up ; down : vkeyboard.digi_down }
                            StdButton { text: "-";  text2: "_"  }
                            StdButton { text: "=";  text2: "+"  }
                        }
                        states:
                       [
                         State { name: "Layout2";
                                 PropertyChanges { target: _456; x: 0; y:esc.height+vkeyboard.spacing;  }
                                 PropertyChanges { target: _789; x: 0; y:(esc.height+vkeyboard.spacing)*2 ;  }
                                 PropertyChanges { target: _0  ; x: 0; y:(esc.height+vkeyboard.spacing)*3;  }

                               },
                         State {name: "Layout1";
                                PropertyChanges { target: _456; y: 0; x:(esc.width+vkeyboard.spacing)*3;  }
                                PropertyChanges { target: _789; y: 0; x:(esc.width+vkeyboard.spacing)*6;  }
                                PropertyChanges { target: _0  ; y: 0; x:(esc.width+vkeyboard.spacing)*9;  }
                               }
                       ]
                       transitions: Transition
                       {
                           NumberAnimation { properties: "x,y,width"; easing.type: Easing.InOutQuad ; duration: 500 }
                       }
                    }// NumericPad


        Row { // qwerty
             id: qwerty ;
             spacing: vkeyboard.spacing; // space between keys
             StdButton { text: "Tab"; text2: " ";  width: esc.width * 1.5 + 0.5 * vkeyboard.spacing  }

             StdButton { text2: "Q" ; key: "q"; up : vkeyboard.key_up ; down : vkeyboard.key_down }
             StdButton { text2: "W" ; key: "w"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "E" ; key: "e"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "R" ; key: "r"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "T" ; key: "t"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "Y" ; key: "y"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "U" ; key: "u"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "I" ; key: "i"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "O" ; key: "o"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text2: "P" ; key: "p"; up : vkeyboard.key_up ; down : vkeyboard.key_down}
             StdButton { text: "["; text2: "{" }
             StdButton { text: "]"; text2: "}" }
             StdButton { text: "\\"; text2: "|";  width: esc.width * 1.5 + 0.5 * vkeyboard.spacing }

            } // qwerty

      Row { // asdfg
          id: asdfg;
          y: qwerty.y + (esc.height+vkeyboard.spacing);
          spacing: vkeyboard.spacing; // space between keys
          StdButton { text: "Caps Lock";
                      text2 : " " ;
                      width: esc.width * 2 + vkeyboard.spacing ;
                      toggleAndSendText: true }

          StdButton { text2: "A" ; key: "a"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "S" ; key: "s"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "D" ; key: "d"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "F" ; key: "f"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "G" ; key: "g"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "H" ; key: "h"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "J" ; key: "j"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "K" ; key: "k"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "L" ; key: "l"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text: ";" ; text2: ":"  }
          StdButton { text: "'" ; text2: "\"" }

          StdButton { text: "Enter"; text2: " " ; width: esc.width * 2 + vkeyboard.spacing }
      }// asdfg

      Row { // zxcvb
          id: zxcvb ;
          y: asdfg.y + (esc.height+vkeyboard.spacing);
          spacing: vkeyboard.spacing; // space between keys

          StdButton { id: shiftKey;
                      text:"Shift";
                      text2:" " ;
                      width: esc.width * 2.5 + 1.5 * vkeyboard.spacing ;
                      toggable: true }

          StdButton { text2: "Z" ; key: "z"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "X" ; key: "x"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "C" ; key: "c"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "V" ; key: "v"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "B" ; key: "b"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "N" ; key: "n"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text2: "M" ; key: "m"; up :  vkeyboard.key_up ; down : vkeyboard.key_down}
          StdButton { text: "," ; text2: "<" }
          StdButton { text: "." ; text2: ">" }
          StdButton { text: "/" ; text2: "?" }
          Rectangle {  color: "#00000000" ; height: esc.height; width: esc.width* 0.5 - 0.5* vkeyboard.spacing }

          StdButton { icon: "pic/up.png"  ; id: upKey ; key: "up_key" }
      }// zxcvb

      Row { // spaceRow
          id: spaceRow;
          spacing: vkeyboard.spacing;
          y: zxcvb.y+ esc.height + vkeyboard.spacing;
          StdButton {id: ctrlKey  ; text: "Ctrl"  ; text2: " " ; toggable: true ; width: esc.width * 1.5 + 0.5 * vkeyboard.spacing }
          StdButton {id: altKey   ; text: "Alt"   ; text2: " " ; toggable: true ; width: esc.width * 1.5 + 0.5 * vkeyboard.spacing }
          StdButton {id: spaceKey ; text: "Space" ; text2: " " ; width: esc.width * 7.5 + 6.5 * vkeyboard.spacing }
          StdButton {id: altgrKey ; text: "AltGr" ; text2: " " ; toggable: true ; width: esc.width * 1.5 + 0.5 * vkeyboard.spacing}

          StdButton {id: leftKey  ; icon: "pic/left.png" ; key: "left_key" }
          StdButton {id: downKey  ; icon: "pic/down.png"  ; key: "down_key" }
          StdButton {id: rightKey ; icon: "pic/right.png" ; key: "right_key" }
      }


    states: [
        State
        {
          extend: 'Layout2'
          name:  "Layout3"
            PropertyChanges { target: numericPad; opacity: 0 }
            PropertyChanges { target: tylda; opacity: 0 }
            PropertyChanges { target: insDel; opacity: 0 }
            PropertyChanges { target: vkeyboard; width: qwerty.width }
        },
        State
        {
            name: "Layout2";
            PropertyChanges { target: qwerty; y: (esc.height+vkeyboard.spacing) }
            PropertyChanges { target: insDel; x: (esc.width+vkeyboard.spacing) * 16 }
            PropertyChanges { target: tylda; x: (esc.width+vkeyboard.spacing) * 15 ; y : 0 }
            PropertyChanges { target: numericPad;  x: (esc.width+vkeyboard.spacing)*15 }
            PropertyChanges { target: backspace; y: 0 }
            PropertyChanges { target: vkeyboard; height: (esc.height+vkeyboard.spacing) * 5; width: (esc.width+vkeyboard.spacing) * 18; }
            PropertyChanges { target: functionKeys ; y:0 }
        },
        State
        {
            name: "Layout1";

            PropertyChanges { target: qwerty; y: (esc.height+vkeyboard.spacing)*2 }
            PropertyChanges { target: insDel; x: (esc.width+vkeyboard.spacing) * 13 }
            PropertyChanges { target: tylda; x:0 ; y : esc.height+vkeyboard.spacing }
            PropertyChanges { target: numericPad;  x: (esc.width+vkeyboard.spacing) }
            PropertyChanges { target: backspace; y: esc.height+vkeyboard.spacing }
            PropertyChanges { target: vkeyboard;  height: (esc.height+vkeyboard.spacing) * 6 ; width: (esc.width+vkeyboard.spacing) * 15 ;}
            PropertyChanges { target: functionKeys ; y:0 }
        }


        ]

    transitions: Transition
    {
        NumberAnimation { properties: "x,y,width,height"; easing.type: Easing.InOutQuad ; duration: 500 }
        NumberAnimation { properties: "opacity"; easing.type: Easing.InOutQuad ;  duration: 500 }
    }
}
