<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 22:22
 */
error_reporting(E_ERROR | E_PARSE);

$data = [
    "test" => "testData"
];

$json = json_encode($data);

print($json);

$port = 30025;
$hostname = "10.10.4.149";
$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
//var_dump(socket_connect($socket, $hostname, $port));
$conn = socket_connect($socket, $hostname, $port);
if($conn) {
    //var_dump(socket_connect($socket, $hostname, $port));
    socket_send($socket, $json, 100, null);
}