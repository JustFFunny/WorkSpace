 function checkTheForm()
  {
    if(document.leavewordform.title.value==""&&document.leavewordform.content.value=="")
	{
	  alert("标题和话题不能为空！");
     }   
  else if(document.leavewordform.title.value=="")
	{
	  alert("标题和话题不能为空！"); 
	  }
  else if(document.leavewordform.content.value=="")
	  {
	    alert("话题内容不能为空！"); 
	 }
	else
	 {
	   document.leavewordform.submit(); 
	   }
 }
  function checkForm()
  {
      if(document.leavewordform.content.value=="")
	  {
	    alert("话题内容不能为空！"); 
	 }
	else
	 {
	   document.leavewordform.submit(); 
	   }
 }