<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="./estilo_administrador.css">
</head>
<body>
<?php
echo    '<div class="status-row">
        <div class="status-summary">';
echo    '<h2 class="status-summary__title"> BIENVENIDO ' . strtoupper($puesto_consulta);
echo    ' ' . strtoupper($nombre_consulta);
echo    ' ' . strtoupper ($apellidos_consulta);
echo    '</h2>
        <button type="button" onclick=location.href="index.php" class="status-summary__button">Cerrar Sesión</button>
        </div>
    </div>
    
    <!-- Sección resumen de monitoreo de kioscos -->
    <div class="status-row">
        <!-- tarjeta De kioscos totales -->
        <div class="status-card status-card--success">
        <h2 class="status-card__title">TEMPERATURA</h2>
        <span class="status-card__number status-card__number--n-error">84</span>
        <p>sin errores</p>
        </div>
        <!-- tarjeta de errores y alertas de impresoras -->
        <div class="status-card">
        <h2 class="status-card__title">HUMEDAD</h2>
        <div class="double-box">
            <!-- Errores de impresora -->
            <div class="status-card-double status-card-double--error">
            <span class="status-card__number status-card__number--y-error">2</span>
            <p>Errores</p>
            </div>
            <!-- Alertas de impresora -->
            <div class="status-card-double status-card-double--alert">
            <span class="status-card__number status-card__number--y-alert">1</span>
            <p>Alertas</p>
            </div>
        </div>
        </div>
        <!-- tarjeta de errores de lectores de tarjeta -->
        <div class="status-card status-card--error">
        <h2 class="status-card__title">POLVO EN EL AMBIENTE</h2>
        <span class="status-card__number status-card__number--y-error">2</span>
        <p>Errores</p>
        </div>
        <!-- tarjeta de errores de lectores de huella -->
        <div class="status-card status-card--error">
        <h2 class="status-card__title">REGISTRO DE ENTRADAS AL CUARTO</h2>
        <span class="status-card__number status-card__number--y-error">1</span>
        <p>Errores</p>
        </div>
        <!-- tarjeta de errores de lectores de huella -->
        <div class="status-card">
        <h2 class="status-card__title">L. de código (20)</h2>
        <span class="status-card__number">0</span>
        <p>Errores</p>
        </div>
    </div>
    
    <!-- Selector de sucursal de errores detallada-->
    <div class="status-row">
        <div class="status-summary">
        <h2 class="status-summary__title">Seleccione una sucursal</h2>
        <select>
            <option value="">Caballito</option>
            <option value="">Almagro</option>
            <option value="">Devoto</option>
            <option value="">San Telmo</option>
        </select>
        </div>
    </div>  
    
    <!-- Tabla con información de tallada de errores y alertas -->
    <div class="status-table">
    <table class="status-table__error-report">
        <thead>
        <tr>
            <th>Kiosco</th>
            <th>Sucursal</th>
            <th>Unidad</th>
            <th>Tipo</th>
            <th>Mensaje</th>
        </tr>
        </thead>
        <tbody>
        <tr>
            <td>#154</td>
            <td>Caballito</td>
            <td>Impresora</td>
            <td>Error</td>
            <td>La impresora no tiene papel</td>
        </tr>
        <tr>
            <td>#241</td>
            <td>Devoto</td>
            <td>Impresora</td>
            <td>Error</td>
            <td>La impresora no tiene papel</td>
        </tr>
        <tr>
            <td>#009</td>
            <td>Almagro</td>
            <td>Impresora</td>
            <td>Error</td>
            <td>Queda poco papel</td>
        </tr>
        <tr>
            <td>#145</td>
            <td>San Telmo</td>
            <td>L. de tarjeta</td>
            <td>Error</td>
            <td>Lector desconectado</td>
        </tr>
        <tr>
            <td>#087</td>
            <td>Caballito</td>
            <td>L. de tarjeta</td>
            <td>Error</td>
            <td>Lector desconectado</td>
        </tr>
        <tr>
            <td>#109</td>
            <td>Almagro</td>
            <td>L. de Huella</td>
            <td>Error</td>
            <td>Lector desconectado</td>
        </tr>
        </tbody>
    </table> 
        <!-- Selector de páginas de la tabla -->
        <ul class="table-pages" >
        <li class="table-pages__page-avaliable">
            <a href="">&#9668;</a></li>
        <li class="table-pages__page-avaliable--selected">
            <a href="">1</a></li>
        <li class="table-pages__page-avaliable">
            <a href="">2</a></li>
        <li class="table-pages__page-avaliable">
            <a href="">3</a></li>
        <li class="table-pages__page-avaliable">
            <a href="">&#9658;</a></li>
        </ul>
    </div>';
?>
</body>
</html>