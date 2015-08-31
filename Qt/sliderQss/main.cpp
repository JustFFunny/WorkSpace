#include <QApplication>
#include <QSlider>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSlider * slider =new QSlider(Qt::Horizontal);

//QSS 设置方法1
////设置滑块的 图标
//    slider->setStyleSheet( "QSlider::handle:horizontal {   \                             "
//    " border: 1px solid #5c5c5c;"
//    " border-image:url(/home/wuqiankun/circle.jpg);"\
//    "width: 18px;"\
//     " margin: -7px -7px -7px -7px; }"  \
//     "QSlider::sub-page:horizontal{background:grb(200,200,1);}"
//     "QSlider::add-page:horizontal{background:grb(255,255,255);  }"
//                           );


 //QSS 设置放大2   /***滑动的槽groove***/
    slider->setStyleSheet(
    "QSlider::groove:horizontal {  \
   border: 1px solid #4A708B;\
   background: #3D3D3F;\
   height: 3px;\
   border-radius: 1px;\
   padding-left:-1px;\
   padding-right:-1px; }"

   /***滑动的手柄handle****/
   "QSlider::handle:horizontal {\
   background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #FFFFFF, stop:0.778409 rgba(255, 255, 255, 255));\
   width: 7px;\
   margin-top: -3px;\
   margin-bottom: -2px;\
   border-radius: 3px;\
   }"

   /********滑过的地方sub-page***/
   "QSlider::sub-page:horizontal { \
   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\
   stop:0 #FFFFFF, stop:1 #FFFFFF);\
   background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\
   stop: 0 #FFFFFF, stop: 1 #FFFFFF);\
   border: 1px solid #FFFFFF;\
   height: 10px;\
   border-radius: 2px;}"


   /* 未滑动的地方add-page*/
   "QSlider::add-page:horizontal {   \
   background: #575757; \
   border: 0px solid #777; \
   height: 10px; \
   border-radius: 2px;  }"   );



   slider ->show();

    
    return a.exec();
}
