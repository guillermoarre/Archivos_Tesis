<?php
$servername = "localhost";
// Nombre de la base de datos
$dbname = "id19485196_pruebadatossensor";
// NOmbre del usuario de la BD
$username = "id19485196_memo";
// RContrasena de la base de datos
$password = "39l8Obf1-RuSsEma";
// Instanciamo el objeto mysqli
$conexion = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conexion->connect_error) {
    die("Falló la conexión a base de datos: " . $conexion->connect_error);
} 
//Consulta a la base de datos alojada en el HOST
$sql = "SELECT no_personal, Nombre_e, Apellido_e, Puesto_e, reading_time FROM Registros ORDER BY reading_time DESC";
//Realizamos la consulta y lo guardamos en el vector $sensor_data[]
$result = $conexion->query($sql);
while ($row = $result->fetch_assoc())
{
    $datos[] = $row;
}

 //cerramos consulta

//comienza documento html
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registros de entradas</title>
    <link rel="stylesheet" href="Tablas_formato.css">
    
    
</head>
<body>
    <?php
        //MAS DATOS DE EMPLE
        //
        echo    "<div align = 'center'>
                <h1>REGISTRO DE ENTRADAS AL CT</h1>
                </div>
                <div align = 'center'>
                <br>
                <table border = '1'>
                    <tr>
                        <td align='center'>NO_EMPLEADO</td>
                        <td align='center'>NOMBRE</td>
                        <td align='center'>APELLIDO</td>
                        <td align='center'>PUESTO</td>
                        <td align='center'>FECHA Y HORA</td>

                    </tr>"; //fin de fila
                    foreach($datos as $dato)
                    {
                      
                    printf("
                        <tr>
                        <td align = 'center'>%s</td>
                        <td align = 'center'>%s</td>
                        <td align = 'center'>%s</td>
                        <td align = 'center'>%s</td>
                        <td align = 'center'>%s</td>
                        </tr>",$dato['no_personal'],$dato['Nombre_e'],$dato['Apellido_e'],$dato['Puesto_e'],$dato['reading_time']);
                    }
        
        echo "</table>";
        $result->free();
        $conexion->close();
            
    ?>


</body>
</html>