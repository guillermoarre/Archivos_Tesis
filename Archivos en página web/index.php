<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Monitoreo y Gestión</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.min.css" integrity="sha512-xh6O/CkQoPOWDdYTDqeRdPCVd1SpvCA9XXcUnZS2FmJNp1coAFzvtCN9BmamE+4aHK8yyUHUSCcJHgXloTyT2A==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <link rel="stylesheet" href="./estilo_login.css">
</head>
<body>
<?php
if (session_start()) session_destroy();

//echo   '<form >
echo   '<div id="login-page">
        <div class="login">
        <br/><br/><br/>
        <h2 class="login-title">Bienvenido</h2>
        <p class="notice">Por favor ingrese sus datos para acceder al sistema</p>
        <form class="form-login" action="principal.php" method="post">
            <label for="email">Usuario</label>
            <div class="input-text">
            <i class="fa-solid fa-user icon"></i>
            <input type="text" name="usuario" placeholder="Ingrese su usuario" required>
            </div>
            <label for="password">Contraseña</label>
            <div class="input-password">
            <i class="fas fa-lock icon"></i>
            <input type="password" name="contrasena" placeholder="Ingrese su contraseña" required>
            </div>
            <button type="submit"><i class="fas fa-door-open"></i> Ingresar </button>
        </form>
            <a href="#">¿Olvidaste tu contraseña?</a>
        <div class="created">
        </div>
        </div>
        <div class="background">
        <h1>SISTEMA DE MONITOREO Y GESTIÓN DE UN CUARTO DE TELECOMUNICACIONES</h1>
        </div>
        </div>';
?>
</body>
</html>