<?php
$servername = "localhost";
// Nombre de la base de datos
$dbname = "id19485196_pruebadatossensor";
// NOmbre del usuario de la BD
$username = "id19485196_memo";
// RContrasena de la base de datos
$password = "39l8Obf1-RuSsEma";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
//Consulta a la base de datos alojada en el HOST
$sql = "SELECT id, value1, value2, value3, reading_time FROM Sensor order by reading_time desc limit 40";

//Realizamos la consulta y lo guardamos en el vector $sensor_data[]
$result = $conn->query($sql);
while ($data = $result->fetch_assoc()){
    $sensor_data[] = $data;
}

//Obtenemos la lectura del dia y hora
$readings_time = array_column($sensor_data, 'reading_time');

// ******* Convertir hora ********
$i = 0;
foreach ($readings_time as $reading){
    $readings_time[$i] = date("d-m-Y H:i:s", strtotime("$reading - 6 hours"));
    $i += 1;
}

//json_decode, retorna el arreglo previamente hecho, json_numeric coloca valor numerico
$value1 = json_encode(array_reverse(array_column($sensor_data, 'value1')), JSON_NUMERIC_CHECK);
$value2 = json_encode(array_reverse(array_column($sensor_data, 'value2')), JSON_NUMERIC_CHECK);
$value3 = json_encode(array_reverse(array_column($sensor_data, 'value3')), JSON_NUMERIC_CHECK);
$reading_time = json_encode(array_reverse($readings_time), JSON_NUMERIC_CHECK);


//cerramos consulta
$result->free();
$conn->close();

//comienza documento html
?>

<!DOCTYPE html>
<html>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="estilos.css">
<script src="https://code.highcharts.com/highcharts.js"></script>
  
  <body>
    <h2>PRUEBA Temperatura y Humedad, ESIME</h2>
    <h3>Temperatura y Humedad</h3>
    <div id="chart-temperature" class="container"></div>
    <div id="chart-humidity" class="container"></div>
    <div id="chart-pressure" class="container"></div>
    

<script>

//pasar valores php a javascript
var value1 = <?php echo $value1; ?>;
var value2 = <?php echo $value2; ?>;
var value3 = <?php echo $value3; ?>;
var reading_time = <?php echo $reading_time; ?>;

var chartT = new Highcharts.Chart({
  chart:{ renderTo : 'chart-temperature' },
  title: { text: 'Temperatura del CT' },
  series: [{
    showInLegend: false,
    data: value1
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#059e8a' }
  },
  xAxis: { 
    type: 'datetime',
    categories: reading_time
  },
  yAxis: {
    title: { text: 'Temperature (Celsius)' }
  },
  credits: { enabled: false }
});

var chartT = new Highcharts.Chart({
  chart:{ renderTo : 'chart-Humedad' },
  title: { text: 'Humedad del CT' },
  series: [{
    showInLegend: false,
    data: value1
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#059e8a' }
  },
  xAxis: { 
    type: 'datetime',
    categories: reading_time
  },
  yAxis: {
    title: { text: 'Humudity ()' }
  },
  credits: { enabled: false }
});

</script>
</body>
</html>