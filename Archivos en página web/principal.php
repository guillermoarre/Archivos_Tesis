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
	session_start();
	//include('conexion.php');
	//include('conectar.php');	
	$_POST['usuario'];
	$_POST['contrasena'];
	
	$usuario = $_POST['usuario'];
	$contra = $_POST['contrasena'];
	$usuario_consulta='';
	$contra_consulta='';
	
	//$link = Conectarse();
	//$link = Conectando();
	//$link =
	$servername = "localhost";
	$database = "id19485196_pruebadatossensor";
	$username = "id19485196_memo";
	$password = "39l8Obf1-RuSsEma";

// Create connection
    $conn = mysqli_connect($servername, $username, $password, $database);
    // Check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    //echo "Connected successfully";
    $result_sql='';
	//$consulta = ("select ID, Puesto, Nombre, Apellidos, Contrasena from Trabajadores where ID='$usuario' and Contrasena='$contra'");
	$sql = "SELECT ID, Puesto, Nombre, Apellidos, Contrasena FROM Trabajadores WHERE ID='$usuario' AND Contrasena='$contra'";
        if ($conn->query($sql) == FALSE) {
            echo "Error: " . $sql . "<br>" . $conn->error;
            exit;
        }
    //echo "New record created successfully";
    $result_sql=$conn->query($sql);
    $perfil=$result_sql->fetch_object();
    $usuario_consulta=$perfil->ID;
    $contra_consulta=$perfil->Contrasena;
	$puesto_consulta=$perfil->Puesto;
	$nombre_consulta=$perfil->Nombre;
	$apellidos_consulta=$perfil->Apellidos;
	
	if($usuario_consulta != '' && $contra_consulta !='')
	{
		$_SESSION['userjob']=$puesto_consulta;
		$_SESSION['username']=$nombre_consulta;
		$_SESSION['userlastname']=$apellidos_consulta;

		include('Administrador.php');
		
		
	}
	
	/*else{
		include('index_fail.php');
	}*/

	mysqli_close($conn);
?>   
</body>
</html>