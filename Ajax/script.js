$(document).ready(function () {
    var html = "<td class=\"senzor-data\" id=\"1\">";
    var html2 = "</td>";
    setInterval(function(){
        $.getJSON('data.json', function(jd) {
        $('#1').replaceWith(html + jd.data + html2 );
        $("#2").replaceWith(html + jd.data2 +html2 );
    });
    }, 3000);
});

