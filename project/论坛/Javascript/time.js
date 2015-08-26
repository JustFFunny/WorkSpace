 dayObj=new Date();

monthStr=dayObj.getMonth()+1;

if(dayObj.getYear()<99)

year2000=2000+dayObj.getYear();  

else year2000=dayObj.getYear();

    document.write("今天是"+year2000+"年"+monthStr+"月"+dayObj.getDate()+"日"+" ");  

if(dayObj.getDay()==1)

document.write("星期一");

if(dayObj.getDay()==2)

document.write("星期二");  

if(dayObj.getDay()==3)

document.write("星期三");

    if(dayObj.getDay()==4)

document.write("星期四");

if(dayObj.getDay()==5)

document.write("星期五");

if(dayObj.getDay()==6)

document.write("星期六");

if(dayObj.getDay()==0)

document.write("星期天");