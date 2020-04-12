var counter = 0;
var judging = 0;

 //监听ENTER键
window.onload=function(){
	footershow();
	document.onkeydown=function(e){
	var event=e || event;
	var temp=document.getElementById("inputing").value;
		if (temp!==""&& event.keyCode==13){
			creat(temp);
			document.getElementById("inputing").value="";
		}
	}
}

//页脚显示功能
function footershow(){
	if(counter === 0){
		document.getElementById("symbol").style.display = "none";
		document.getElementById("bodying_foot").style.display = "none";
		document.getElementById("footer_top1").style.display = "none";
		document.getElementById("footer_top2").style.display = "none";
	}else{
			document.getElementById("symbol").style.display = "block";
			document.getElementById("bodying_foot").style.display = "block";
			document.getElementById("footer_top1").style.display = "block";
			document.getElementById("footer_top2").style.display = "block";
			document.getElementById("iterm").innerHTML=counter+" "+"iterms left";
	}
}

//向HTML添加div
function creat(temp){
	var sect=document.getElementById("bodying_section");
	var mydiv=document.createElement("div");
	var myinput=document.createElement("input");
	var mylabel=document.createElement("label");
	var myspan=document.createElement("span");
	
	mylabel.setAttribute('onmouseout','displayspan1()');
	mylabel.setAttribute('onmouseover','displayspan2()');
	myspan.setAttribute('onmouseout','displayspan3()');
	myspan.setAttribute('onmouseover','displayspan4()');
	myinput.setAttribute('type','checkbox');
	myinput.setAttribute('onclick','label_change()');
	mylabel.innerText=temp;
	mylabel.setAttribute('contenteditable','true');
	myspan.innerText="x";
	myspan.setAttribute('onclick','cleardiv()');
	
	sect.appendChild(mydiv);
	mydiv.appendChild(myinput);
	mydiv.appendChild(mylabel);
	mydiv.appendChild(myspan);
	
	counter++;
	footershow();
}


//改变CheckBox的状态
function label_change(){
	var changeLabel=event.target.nextElementSibling;
	if ( event.target.checked==true){
		changeLabel.setAttribute('style',"text-decoration: line-through;color: #e6e6e6;");
		}else{
			changeLabel.removeAttribute("style");
		}
}

//span的状态
function displayspan1(){
	var showspan=event.target.nextElementSibling;
		showspan.style.display = "none";
}
function displayspan2(){
	var showspan=event.target.nextElementSibling;
		 showspan.style.display = "block";
}
function displayspan3(){
	var showspan=event.target;
		showspan.style.display = "none";
}
function displayspan4(){
	var showspan=event.target;
		showspan.style.display = "block";
}

//﹀功能
function symboltest(){
	var btn=document.getElementsByTagName("button");
	var checking=document.getElementsByTagName("input");
	
	if(judging===0) {
		for(var i=1;i<checking.length;i++){
			if(checking[i].checked===false){
				completed();
				judging=0;
				break;
			}else{
				nocompleted();
				break;
			}
		}
	}
	
	if(judging===1){
		if(document.getElementById("bodying_section").style.display=="block"){
				document.getElementById("bodying_section").style.display="none";
				btn[3].style.display="none";
		}else{
				document.getElementById("bodying_section").style.display="block";
				btn[3].style.display="block";
		}
	}
}

//除去div
function cleardiv(){
	counter--;
	var deletediv = event.target.parentNode;
	var middle_section = deletediv.parentNode;
	middle_section.removeChild(deletediv);
	footershow();
}

//all按钮
function allBtn(){
	judging=0;
}

//activ按钮功能
function activing(){
	judging=1;
	var checking=document.getElementsByTagName("input");
	for(var i=1;i<checking.length;i++){
		checking[i].checked=false;
		checking[i].disabled="disabled";
		checking[i].nextElementSibling.removeAttribute("style");
	}
}

//completed按钮功能
function completed(){
	judging=1;
	var checking=document.getElementsByTagName("input");
	for(var i=1;i<checking.length;i++){
		checking[i].checked=true;
		checking[i].removeAttribute("disabled");
		if ( checking[i].checked===true){
				checking[i].nextElementSibling.setAttribute('style',"text-decoration: line-through;color: #e6e6e6;");
			}else{
			checking[i].nextElementSibling.removeAttribute("style");
		}
	}
}

//checkbox全部不被选中
function nocompleted(){
	var checking=document.getElementsByTagName("input");
	for(var i=1;i<checking.length;i++){
		checking[i].removeAttribute("disabled");
		checking[i].checked=false;
		checking[i].nextElementSibling.removeAttribute("style");
	}
}

//clear completed按钮功能
function clear_completed(){
	var checking=document.getElementsByTagName("input");
	for(var i=1;i<checking.length;i++){
		if ( checking[i].checked==true){
			checking[i].parentNode.parentNode.removeChild(checking[i].parentNode);
			i--;
			counter--;
		}
	}
	footershow();
}