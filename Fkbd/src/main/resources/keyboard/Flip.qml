import Qt 4.7

Flipable {
     id: flipable

     property int angle: 0


     transform: Rotation {
         id: rotation
         origin.x: flipable.width/2; origin.y: flipable.height/2
         axis.x: 1; axis.y: 0; axis.z: 0     // rotate around y-axis
         angle: flipable.angle
     }

   states:
   State {
         name: "back" ;
         PropertyChanges { target: flipable; angle: -180 }
     }


    transitions: Transition {
        NumberAnimation  { properties: "angle"; duration: 500 }
     }


 } // flipable
