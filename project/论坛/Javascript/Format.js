function insertFormat()
		{
		   format.innerHTML ="增加版块";
		   addFormat.innerHTML ="<form onSubmit='/cgi-bin/AddBlock.cgi' action='/cgi-bin/AddBlock.cgi' method=get>增加新的版块<hr>版块名称<br><input name='blockname' type='text' id='name' size='25'><hr>添加版主<br><input type='radio' name='addmaster' id='radio3' value='1' checked>是<input type='radio' name='addmaster' id='radio3' value='0'>否<hr>版主用户名<br><input name='mastername' type='text' id='formatName' size='25'><hr><input type='submit' id='button' value='  提交  '></form>";
		}
		function AdminFormat()
		{
		  format.innerHTML ="管理版块";
		  addFormat.innerHTML ="<form onSubmit='/cgi-bin/AlterBlock.cgi' action='/cgi-bin/AlterBlock.cgi' method=get>版块管理<input type='button' name='Update' id='Update' value='修改' onClick='AdminFormat()'><input type='button'  id='delete' value='删除' onClick='DeleteFormat()'><hr>原版块名称<br><input name='oldname' type='text' id='oldname' size='25'><hr>修改后版块名称<br><input name='newname' type='text' id='newname' size='25'><hr>添加版主<br><input type='radio' name='addmaster' id='radio3' value='1' checked>是<input type='radio' name='addmaster' id='radio3' value='0'>否<hr>版主用户名<br><input name='mastername' type='text' id='formatName' size='25'><hr><input type='submit' id='button' value='修改版块'></form>";
		}
		function DeleteFormat()
		{
		  addFormat.innerHTML ="<form onSubmit='/cgi-bin/DeleteBlock.cgi' action='/cgi-bin/DeleteBlock.cgi' method=get>版块管理<input type='button' name='Update' id='Update' value='修改' onClick='AdminFormat()'><input type='button'  id='delete' value='删除'><hr>版块名称<br><input name='blockname' type='text' id='name' size='25'><hr><input type='submit' id='button' value='删除版块'></form>";
		}