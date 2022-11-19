<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php 
    //echo "conectarse";
    ini_set('display_errors', 1);
    ini_set('display_startup_errors', 1);
    error_reporting(E_ALL);

    function Conectarse() 
    { 
        $servername = "localhost";
        // Nombre de la base de datos
        $dbname = "id19485196_pruebadatossensor";
        // NOmbre del usuario de la BD
        $username = "id19485196_memo";
        // RContrasena de la base de datos
        $password = "39l8Obf1-RuSsEma";
    //$dsn= "Driver={SQL Server};
    //Server=LAPTOP-5HVFOTRG;Database=Monitoreo_Gestion;";

    $conn = new mysqli($servername, $username, $password, $dbname);
    if ($conn->query($sql) === TRUE)
    { 
        echo "Error conectando a la base de datos."; 
        exit(); 
    } 
        else{
    //echo "<br> conecto";
    }
    return $link; 
    } 
?>
</body>
</html>