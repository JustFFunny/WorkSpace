import Qt 4.7

Rectangle { 
    id: button;

    property string command : "none"
    property alias text: label.text
    property alias icon: image.source
    property int imageheight: button.width - 8  
    property bool toggable: false
    property bool toggled: false

    property color up : "#0068c3"
    property color down : "#0071ae"

    signal clicked


    width: 136 ;
    height: layout.height+8;

    border.color: "#bcbcbc";
    border.width: 1;
    //smooth: true;
    radius: 6
    color : "black"

      Item
      {
         anchors.centerIn : parent;
         height: image.height + label.height
         id:layout;

             Image { id: image;
                 smooth: true;
                 width: button.width-8;
                 height: button.imageheight;
                 anchors.horizontalCenter: layout.horizontalCenter
             }
            Text {  id: label;

                // anchors.centerIn: button;
                 anchors.horizontalCenter: layout.horizontalCenter
                 anchors.top: image.bottom
                 anchors.topMargin: 5
                 color: "white";
                 font.pointSize: 11;
                 font.family: "Bitstream Vera Sans";
              }
     }//Column
    MouseArea {
        id: clickRegion
        anchors.fill: parent
        onClicked: {
          
            button.clicked()
            vkbd.restore()
            console.log("Executing:",button.command)
            Qt.openUrlExternally(button.command)
            if (!button.toggable) return;
            button.toggled ? button.toggled = false : button.toggled = true ;

        }
    }

    states: [
        State {
            name: "Pressed"; when: clickRegion.pressed == true
       //     PropertyChanges { target: G1; color: button.up }
      //      PropertyChanges { target: G4; color: button.down }
             PropertyChanges { target: button ; y: button.y + 10 }

        },
        State {
            name: "Toggled"; when: button.toggled == true
    //        PropertyChanges { target: G1; color: button.up }
    //        PropertyChanges { target: G4; color: button.down }

        }

    ]
}
