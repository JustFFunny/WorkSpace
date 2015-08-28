import Qt 4.7

Rectangle {
    id: button; width: 50  ; height: 40
    signal clicked()

    function release()
    {
      toggled = false;
      vkbd.keyUp(key);
    }

    radius: 6

    property alias text: label.text
    property alias text2: label2.text

    property alias textAnchors: label.anchors
    property alias textFont: label.font
    property alias icon: img.source

    property string key : text


    property bool toggable: false
    property bool toggled: false
    property bool toggleAndSendText : false


    property color up_pressed : "#0068c3"
    property color down_pressed : "#0071ae"

    property color up : "#3d3d3d"
    property color down : "#585858"


//    border.color: "#bcbcbc"; // palette.mid;
    border.width: 1;
    smooth: true;


    gradient: Gradient {
     GradientStop { id: g1; position: 0.0; color: up   }
     GradientStop { id: g2; position: 1; color: "#040404" }
    }

    Rectangle
    { id: lower
       width: parent.width - parent.height * 0.12
       height: parent.height - parent.height * 0.12
       smooth: true
       radius: 4
       anchors.centerIn: parent;
       gradient: Gradient {
       GradientStop { id: g3; position: 0; color: "#151515" }
       GradientStop { id: g4; position: 1.0; color: down }

       }
        Column {

            Text {  id: label2;
                x: 11;
                color: "white";
                font.pointSize: 10;
                //font.bold: true;
                font.family: "Bitstream Vera Sans";
            }

            Text {  id: label;
                x: 11;
                color: "white";
                font.pointSize: 9;
                font.bold: true;
                font.family: "Bitstream Vera Sans";
            }

        }
        Image
        { id : img
            anchors.centerIn: parent

        }
        MouseArea {
            id: clickRegion
            anchors.fill: parent
            onClicked: {
                button.clicked()
                if (button.toggleAndSendText)
                {
                    button.toggled = !button.toggled;
                    vkbd.typeText(key);
                    return;
                }

                if (!button.toggable)
                {
                    vkbd.typeText(key);
                    return;
                }
                if (!button.toggled )
                {
                    vkbd.keyDown(key);
                    button.toggled = true;
                }
                else
                {
                    vkbd.keyUp(key);
                    button.toggled = false;
                }

            }
        }
    }
    states: [
        State {
            name: "Pressed"; when: clickRegion.pressed == true
            PropertyChanges { target: g1; color: button.up_pressed }
            PropertyChanges { target: g4; color: button.down_pressed }
        },
        State {
            name: "Toggled"; when: button.toggled == true
            PropertyChanges { target: g1; color: button.up_pressed }
            PropertyChanges { target: g4; color: button.down_pressed }

        }
    ] // States


}
