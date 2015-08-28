import Qt 4.7

Rectangle {
    id: button;

    width: rowLayout.width * 1.2 ; // 200
    //width: 50
    height: 32
    signal clicked
    //signal toggled
    property alias text: label.text
    property alias icon: image.source
    property alias font: label.font


    property bool toggable: false
    property bool toggled: false
    property color up : "#0068c3"
    property color down : "#0071ae"
    property color defUp : "#3d3d3d"
    property color defDown: "#585858"

    property bool typeText: false

    function toggle()
    {
      button.toggled == true ? button.toggled = false : button.toggled = true;
    }

   // border.color: "#bcbcbc";
   // border.width: 1;
    smooth: true;
    radius: 6

    gradient: Gradient {

        GradientStop { id: g1; position: 0.0; color: defUp }
        GradientStop { id: g2; position: 1; color:  "#040404"  }
    }
     Rectangle
     {
         anchors.centerIn:parent
         width: parent.width - parent.height * 0.12
         height: parent.height - parent.height * 0.12
         radius: 4
         smooth: true
         gradient: Gradient {
         GradientStop { id: g3; position: 0; color: "#151515" }
         GradientStop { id: g4; position: 1.0; color: defDown }
         }

        Row
        { id: rowLayout
          anchors.centerIn: parent;
          spacing: 5
        Image{ id: image }
         Text {  id: label;
                 color: "white";
                 font.pointSize: 10;
                 font.family: "Bitstream Vera Sans";
                 anchors.verticalCenter: parent.verticalCenter
              }
        }

     }

    MouseArea {  id: clickRegion
        anchors.fill: parent
        hoverEnabled : true


        onPressed:{ vkbd.setPressed(true);
             if (typeText)
             {
               vkbd.typeText(text); //releaseKeys();
               //keyboard.typeText(text);
             }
          }

        onReleased:
        {
            vkbd.setPressed(false);
            if (!keyboard.moved)
            {
              if (!button.toggable)
              {
               button.clicked();
               return;
              }
              button.toggle();
              button.clicked();
           }
        }
    } // MouseRegion

    states: [
        State {
            name: "Pressed"; when: clickRegion.pressed == true
            PropertyChanges { target: g1; color: button.up }
            PropertyChanges { target: g4; color: button.down }
        },
        State {
            name: "Toggled"; when: button.toggled == true
            PropertyChanges { target: g1; color: button.up }
            PropertyChanges { target: g4; color: button.down }
        }
    ]
}
