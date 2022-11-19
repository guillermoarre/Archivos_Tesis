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

$api_key = $value1 = $value2 = $value3 = "";

//Empezar peticion
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        //Entra solamente si la KEY coincide con la de la tarjeta
        $value1 = test_input($_POST["value1"]);
        $value2 = test_input($_POST["value2"]);
        $value3 = test_input($_POST["value3"]);
        
        // Crea una conexion
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Verifica la conexion
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        $sql = "INSERT INTO Sensor (value1, value2, value3)
        VALUES ('" . $value1 . "', '" . $value2 . "', '" . $value3 . "')";
        
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