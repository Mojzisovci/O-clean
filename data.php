<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 22:22
 */

$data = [
    "test" => "testData"
];

$json = json_encode($data);

print($json);

$port = 30025;
$hostname = "10.10.4.132";
$socket = socket_create($socket, $hostname, SQL_TCP);

if($socket === false) echo "Chyba ve vytvoreni socketu";
