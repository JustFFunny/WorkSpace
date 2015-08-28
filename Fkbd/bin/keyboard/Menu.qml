import Qt 4.7


Grid
{
    columns: 4
    rows : 1   
    spacing: 15

    LaunchButton {
                    text: "ProFace" ; icon : "icons/proface.png"
                    command : "http://www.proface.pl"
                 }


    LaunchButton {
                   text: "3electrons"       ; icon : "icons/3e.png"
                   command: "http://www.3electrons.com/www/en/news/23.html"
                 }

    LaunchButton {
                   text: "Reboot"    ; icon : "icons/system-reboot.png"
                   command : "reboot.lnk"
                 }
    LaunchButton {
                   text: "Power Off"  ; icon : "icons/system-shutdown.png"
                   command : "shutdown.lnk"
                 }

}// layout

