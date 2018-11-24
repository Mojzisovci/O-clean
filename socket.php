<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 18:23
 */

echo 'Socket';
$data = $_GET['name'];
$myfile = fopen("newfile.txt", "w") or die("Unable to open file!");
fwrite($myfile, $data);
fclose($myfile);