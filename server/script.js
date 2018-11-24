$(document).ready(function () {
    var html2 = "</td>";
    setInterval(function(){
        $.getJSON('data.json', function(jd) {
        $('#1').replaceWith("<td class=\"senzor-data\" id=\"1\">" + jd.data + html2 );
        $("#2").replaceWith("<td class=\"senzor-data\" id=\"2\">" + jd.data2 + html2 );
        $("#3").replaceWith("<td class=\"senzor-data\" id=\"3\">" + jd.data3 + html2 );
        $("#4").replaceWith("<td class=\"senzor-data\" id=\"4\">" + jd.data4 + html2 );
    });
    }, 5050);
});

