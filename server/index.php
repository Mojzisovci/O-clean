<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 18:23
 */
error_reporting(E_ERROR | E_PARSE);

if($_POST['direction'] != null OR $_POST['speed']!=""){

    $data['direction'] = $_POST['direction'];
    $data['speed'] = $_POST['speed'];
    //var_dump($data);
    //var_dump($_POST['direction']);
    //die();
    $json = json_encode($data);

    print($json);
    $port = 30025;
    $hostname = "10.10.4.149";
    $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
//var_dump(socket_connect($socket, $hostname, $port));

    if(socket_connect($socket, $hostname, $port)) {
        //var_dump(socket_connect($socket, $hostname, $port));
        socket_send($socket, $json, 100, null);
    }else{
        socket_connect($socket, $hostname, $port);
    }
}
?>
<!DOCTYPE html>
<html lang="cs">
<head>
    <script
        src="https://code.jquery.com/jquery-3.3.1.min.js"
        integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="
        crossorigin="anonymous"></script>
    <meta charset="UTF-8">
    <title>Hackathon</title>
    <script src="script.js"></script>
    <link rel="stylesheet" type="text/css" href="design.css">
    <link rel="stylesheet" type="text/css" href="//fonts.googleapis.com/css?family=Open+Sans" />
    <link rel="icon" href="favicon.png">
</head>
<body>
<div>
    <form  method="post">
    <table>
        <tr><th border-radius: 15px;>Sensors</th><th>Values</th></tr>
        <tr><td class="sensor r">Temperature: </td><td class="senzor-data r" id="1"></td> </tr>
        <tr><td class="sensor r">Engine-left: </td><td class="senzor-data r" id="2"></td></tr>
        <tr><td class="sensor r">Engine-right: </td><td class="senzor-data r" id="3"></td></tr>
        <tr><td class="sensor r">Distance: </td><td class="senzor-data r" id="4"></td></tr>
        <tr><td colspan="2"><label for="speed">Speed:</label>
                <select name="speed">
                    <option value=""></option>
                    <option value="0">0</option>
                    <option value="25">25</option>
                    <option value="50">50</option>
                    <option value="75">75</option>
                    <option value="100">100</option>
                    </select>                               </td><td></td></tr>

        <tr><td><input type="radio" id="left" name="direction" value="0">
                <label for="left">Left</label>                                          </td>

            <td><input type="radio" id="right" name="direction" value="1">
                <label for="huey">Right</label>                                        </td></tr>

        <tr><td colspan="2"><button type="submit" name="submit">Send</button><br>
    </form> </td></tr>

    <tr><td colspan="2"><img src="favicon.png" height="400" width="800"></td><td></td></tr>

    </table>

    <!--<form  method="post">
        <label for="speed">Speed:</label>
        <select name="speed">
            <option value=""></option>
            <option value="0">0</option>
            <option value="25">25</option>
            <option value="50">50</option>
            <option value="75">75</option>
            <option value="100">100</option>
        </select>-->

        <!--<input type="radio" id="left" name="direction" value="0">
        <label for="left">Left</label>

        <input type="radio" id="right" name="direction" value="1">
        <label for="huey">Right</label>

        <button type="submit" name="submit">Send</button><br>
    </form>-->


</div>
</body>

