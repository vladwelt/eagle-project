
var Firebase = require('firebase');
var dron = new Firebase('https://radiant-heat-1615.firebaseio.com/');
var datosAereo = dron.child("eagleproject");
datosAereo.push().set({
	temperatura: "23.21",
	humedad: "322",
	orientacion: "12,1"
});

dron.on("child_added", function(snapshot){
	//console.log("Elemento ha sido agregado "+snapshot.val());
	var dato=snapshot.val();
	//console.log(dato);
});
dron.orderByChild("temperatura").on("child_added",function(snapshot){
	//console.log(snapshot.val());
	var snapshot_list = snapshot.val();
	for(var value in snapshot_list) {
		console.log(snapshot_list[value].temperatura);
	}
});