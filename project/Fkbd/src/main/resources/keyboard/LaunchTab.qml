import Qt 4.7

Item {

   id: launchtab;
  // color: "#00000000"
   anchors.centerIn: parent;
   smooth: true;
  // radius: 5 ;

   Loader { id: pageLoader
       x:25 ;
       y:25;

       anchors.centerIn : parent;
       source :  programsUrl+"/Menu.qml"
   }

}
