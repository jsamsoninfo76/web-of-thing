var nb_led = 6;

function init(){
	//Declaration des left des différentes leds 
	var current_coord = new Array(0,0);
	var current_size = new Array(0,0);
	var led_left = new Array(21,48,75,101,65,65,34,68,104);
	var led_top = new Array(263,263,263,263,4,104,86,50,87);
	var target;
	var src = "img/led_on.jpg";
	
	for (var i=0 ; i<nb_led; i++){
		if (i<4)
		{
			current_size[0] = 25;
			current_size[1] = 10;
			target = "mbed";
		}
		else if (i>=4 && i<=6)
		{
			current_size[0] = 24
			current_size[1] = 19;
			target = "ethernet";	
		}
		else
		{
			current_size[0] = 35
			current_size[1] = 35;
			target = "fleches";	
			src = "img/grey.jpg";
		}
		
		current_coord = getPosition(target);
		
		/* Parametre de l'image */
		document.getElementById("led"+i).src = src;
		document.getElementById("led"+i).style.position = "absolute";
		document.getElementById("led"+i).style.left = (current_coord[0] +led_left[i]) + "px";
		document.getElementById("led"+i).style.top = (current_coord[1] + led_top[i]) + "px";
		document.getElementById("led"+i).style.width = current_size[0]+"px";
		document.getElementById("led"+i).style.height = current_size[1]+"px";
		
		ajaxGet(i,'&init=1');
	}
}

function ajaxGet(url,arg) {
	var xhr;
	url = url + arg;
	
	try{ 		xhr = new XMLHttpRequest(); 					}	
	catch(e){ 	xhr = new ActiveXObject('Microsoft.XMLHTTP'); 	}
	
	xhr.onreadystatechange = function(){
		setImage(xhr,arg);
	};
	xhr.open("GET", url, true);
	xhr.send(null);
}

function setImage(xhr,arg)
{
	if(xhr.readyState == 4 && xhr.status == 200)
	{	
		var etat = xhr.responseText;
		var div = (arg >= 0 && arg <= 5) ? "dled" : "flech_";
		
		document.getElementById("dled"+arg).style.display = (etat == '1') ? "block" : "none";
	}
}

function getPosition(element)
{
	var left = 0;
	var top = 0;
	/*On récupère l'élément*/
	var e = document.getElementById(element);
	/*Tant que l'on a un élément parent*/
	while (e.offsetParent != undefined && e.offsetParent != null)
	{
		/*On ajoute la position de l'élément parent*/
		left += e.offsetLeft + (e.clientLeft != null ? e.clientLeft : 0);
		top += e.offsetTop + (e.clientTop != null ? e.clientTop : 0);
		e = e.offsetParent;
	}
	return new Array(left,top);
}