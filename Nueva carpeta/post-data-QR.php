<?php

$servername = "localhost";
// Nombre de la base de datos
$dbname = "id19485196_pruebadatossensor";
// NOmbre del usuario de la BD
$username = "id19485196_memo";
// RContrasena de la base de datos
$password = "39l8Obf1-RuSsEma";

//Contrasena de la API para seguridad, debe de coincidir con la de la tarjeta
$api_key_value = "tPmAT5Ab3j7F9";

$api_key = $value1 = $fecha_actual = "";
date_default_timezone_set('America/Mexico_City'); 
$fecha_actual = date("Y-m-d H:i:s");
//Empezar peticion
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        //Entra solamente si la KEY coincide con la de la tarjeta
        $value1 = test_input($_POST["value1"]);
        
        // Crea una conexion
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Verifica la conexion
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        $sql2 = "SELECT Nombre, Apellidos, Puesto FROM Trabajadores WHERE ID = '$value1'";
        $result = $conn->query($sql2);
        while ($row = $result->fetch_assoc())
        {
            $datos[] = $row;
        }
        foreach($datos as $dato)
        {
            $nombre_q = $dato['Nombre'];
            $apellido_q = $dato['Apellidos'];
            $puesto_q = $datos['Puesto'];

        }
        $sql = "INSERT INTO Registros (no_personal, reading_time, Nombre_e, Apellido_e,Puesto_e) VALUES ('" . $value1 . "','".$fecha_actual ."'
        ,'".$nombre_q."','".$apellido_q."','".$puesto_q."')";
        
        if ($conn->query($sql) == TRUE) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }
}
else {
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}