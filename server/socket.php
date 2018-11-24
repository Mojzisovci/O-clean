<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 18:23
 */
error_reporting(E_ERROR | E_PARSE);

$data = $_GET;
$data = json_encode($data);
file_put_contents('data.json', $data);
