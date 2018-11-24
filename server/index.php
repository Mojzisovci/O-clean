<?php
/**
 * Created by PhpStorm.
 * User: Rostislav Kral
 * Date: 23.11.2018
 * Time: 18:23
 */

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
</head>
<body>
<div>
    <table>
        <tr><th border-radius: 15px;>Senzors</th><th>Values</th></tr>
        <tr><td class="sensor r">teplota</td><td class="senzor-data r" id="1"></td> </tr>
        <tr><td class="sensor r">rychlost</td><td class="senzor-data r" id="2"></td></tr>
        <tr><td class="sensor r">senzor 3</td><td class="senzor-data r" id="3"></td></tr>
        <tr><td class="sensor r">senzor 4</td><td class="senzor-data r" id="4"></td></tr>
    </table>

    <form method="post">
        <div>
            <label for="say">Write coordinate x: </label>
            <input name="coo" id="x">
        </div>
        <div>
            <label for="to">Write coordinate y: </label>
            <input name="coo" id="y">
        </div>
        <div>
            <button type="submit">Send values</button>
        </div>
    </form>

</div>
</body>

