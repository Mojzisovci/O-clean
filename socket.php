<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 18:23
 */

echo 'Socket';
$data = $_GET;
$data = json_encode($data);
file_put_contents('data.json', $data);
