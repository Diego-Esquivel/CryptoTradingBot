function thefunction() {
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
		   // Typical action to be performed when the document is ready:
		   document.getElementById("info").innerHTML = xhttp.responseText;
		}
	};
	xhttp.open("GET", "http://127.0.0.1:126", true);
	xhttp.send();
}

function createEventListener()	{
	if(document.getElementById("yes").addEventListener)	{
		document.getElementById("yes").addEventListener("click", thefunction, false);
	} else if(document.getElementById("yes").attachEvent)	{
		document.getElementById("yes").attachEvent("onclick", thefunction);
	}
	
	if(document.getElementById("no").addEventListener)	{
		document.getElementById("no").addEventListener("click", thefunction, false);
	} else if(document.getElementById("no").attachEvent)	{
		document.getElementById("no").attachEvent("onclick", thefunction);
	}
}// end function createEventListener() to create event listeners for button, 'enter' key;


function setupPage() {
	createEventListener();
	//var newQ = "Question #" + (1+qIndex) + " " + list[qIndex];
	//qIndex++;
	//$("h2").html(newQ);
	//document.getElementById("MC1").style.display = "none";
}// end function setupPage() which sets up page through calls to createEventListener(), starting first question, and hiding unneccesary inputs;


if(window.addEventListener) window.addEventListener("load",setupPage, false);
else if(window.attachEvent) window.attachEvent("onload", setupPage);
// end onload even listeners;