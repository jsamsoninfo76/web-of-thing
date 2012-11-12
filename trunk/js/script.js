var leds = new Array(0,0,0,0); 

/*function ajaxGet(url,nled,callBack,arg) {*/
function ajaxGet(nled) {
	var xhr;
	var url;
	var mbed;

	//if (leds[nled] == 0) leds[nled] = 1;
	//else leds[nled] = 0;
	
	//Changement de l'état des LED
	leds[nled] = (leds[nled] == 0) ? leds[nled] = 1 : leds[nled] = 0;
	
	//Generation du code HTML pour supperposition d'image
	mbed = document.getElementById("mbed");
	mbed.innerHTML = '<img id=fond src=img/mbed.jpg usemap=#leds>';
	for (var i=0 ; i<leds.length ; i++){
		if (leds[i] == 1)
			mbed.innerHTML += '<div width=23 height=10><a href=javascript:ajaxGet(' + i + ')><img id=led' + i + ' src="img/led_on.jpg"></a></div>';

	}
	mbed.innerHTML += '<map name=leds>';
	mbed.innerHTML += '<area shape="rect" coords="20,260,45,275" href="javascript:ajaxGet(0)" alt="led1"/>';
	mbed.innerHTML += '<area shape="rect" coords="48,260,73,275" href="javascript:ajaxGet(1)" alt="led2"/>';
	mbed.innerHTML += '<area shape="rect" coords="75,260,100,275" href="javascript:ajaxGet(2)" alt="led3"/>';	
	mbed.innerHTML += '<area shape="rect" coords="101,260,126,275" href="javascript:ajaxGet(3)" alt="led4"/>';	
	mbed.innerHTML += '</map>';
	
	url = 'led?nled=' + nled + '&etat=' + leds[nled]; 
	
	/*try{ 
		//Test sur la création d'une requête HTTP
		xhr = new XMLHttpRequest();
	}	
	catch(e){ 
		xhr = new ActiveXObject('Microsoft.XMLHTTP'); 	
	}*/
	
	//Ouverture et envoie de la requête en GET
	//xhr.open("GET", url, true);
	//xhr.send(null);
}
