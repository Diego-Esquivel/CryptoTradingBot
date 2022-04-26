document.getElementById("yes").addEventListener("click",function(){
	if(window.addEventListener) 
	window.addEventListener("click",() => {document.location.href = "http://127.0.0.1:126";});
	else if(window.attachEvent) 
	window.attachEvent("onclick", () => {document.location.href = "https://127.0.0.1:126";});

});
document.getElementById("no").addEventListener("click",function(){
	if(window.addEventListener) 
        window.addEventListener("load",() => {document.location.href = "http://127.0.0.1:126";});
    else if(window.attachEvent) 
        window.attachEvent("onload", () => {document.location.href = "https://127.0.0.1:126";});
});