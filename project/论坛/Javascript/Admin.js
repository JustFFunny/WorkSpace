 function insertUser()
  {
	 word.innerHTML="添加用户";
	 see.innerHTML="<form onSubmit='/cgi-bin/AddUser.cgi' action='/cgi-bin/AddUser.cgi' method=get>添加新用户<hr>用户名<br><input name='username' type='text' id='username' size='25' /><br>密 码<br><input name='password' type='password' id='password' size='25' /><br>Email<br><input name='email' type='text' id='email' size='25' /><br>用户组<br><select name='select' id='select'><option value = '0' selected>新手上路</option></select><br><br><input type='submit' value='提    交'/></form>";
	 //see.innerHTML="";
  }

  function ForbidUser()
  {
	word.innerHTML="禁止用户";
	see.innerHTML="<form onSubmit='/cgi-bin/ForbidUser.cgi' action='/cgi-bin/ForbidUser.cgi' method=get>禁止用户<hr>禁止用户名<br><input name='username' type='text' id='username' size='25' /><hr><br>禁止类型<br><input type='radio' name='type' id='radio' value='1'>正常状态<br><input type='radio' name='type' id='radio' value='2' checked>禁止发言<br><input type='radio' name='type' id='radio' value='3'>禁止访问<hr><br>删除该用户的帖子:<input type='radio' name='delete' id='radio2' value='1'>是<input type='radio' name='delete' id='radio2' value='0' checked>否<br><br><input type='submit' value='执行'/></form>";
  }