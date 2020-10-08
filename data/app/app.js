function handleClick(adonde){
  fetch('/'+adonde)
  .then(response => response.json())
  .then(data => console.log(data.mensaje));;
}