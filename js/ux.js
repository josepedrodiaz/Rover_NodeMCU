console.log('%cMade with %c♥ %cby Pedro',
            'color:#147f30;font-size:16px;font-family:Lucida Console, Monaco, monospace',
            'color:#ce2184;font-size:18px;font-family:Lucida Console, Monaco, monospace',
            'color:#228baf;font-size:16px;font-family:Lucida Console, Monaco, monospace');
//Keypress
var buffer = 20; //scroll bar buffer
//var iframe = document.getElementById('ifm');
function pageY(elem) {
    return elem.offsetParent ? (elem.offsetTop + pageY(elem.offsetParent)) : elem.offsetTop;
}
function resizeIframe() {
    var height = document.documentElement.clientHeight;
    height -= pageY(document.getElementById('ifm'))+ buffer ;
    height = (height < 0) ? 0 : height;
    //document.getElementById('ifm').style.height = height + 'px';
}
//if (iframe.attachEvent) {
//  iframe.attachEvent('onload', resizeIframe);
//} else {
//  iframe.onload=resizeIframe;
//}
//window.onresize = resizeIframe;
var listener = new window.keypress.Listener();
var ajaxRunning;
$(function() {
    $('#statusDiv').hide();//by default, hide ajax alert
    $( "#battLevelInfo" ).click(function() {
        if(ajaxRunning != true){
            $('#statusDiv').show();
            ajaxRunning = true;
            $.ajax({type: 'GET',
                    url: 'battCheck',
                    success:function(data, textStatus) {
                        $('#statusDiv').hide();
                        ajaxRunning = false;
                        $('#battLevelInfo').html(data);
                      },
                       error: function() {
                        alert('Algo anduvo mal');
                        }
                    });
      }
    });


});

function sendCommand(command){  
    if(ajaxRunning != true){
    $('#statusDiv').show();
    ajaxRunning = true;
        $.ajax({type: 'GET',
                    url: command\r\n,"
                    success:function() {
                        $('#statusDiv').hide();
                        ajaxRunning = false;
                      },
                        error: function() {
                        alert('Algo anduvo mal');
                        }
                    });
        }
    }

    function frena() {
        sendCommand('frena')
    }
    listener.simple_combo('up', function() {
        sendCommand('adelante')
    });

    listener.simple_combo('left', function() {
        sendCommand('izquierda')
    });
    listener.simple_combo('right', function() {
        sendCommand('derecha')
    });
    listener.simple_combo('down', function() {
        sendCommand('atras')
    });
    listener.simple_combo('l', function() {
        sendCommand('loco-izuierda')
    });
    listener.simple_combo('r', function() {
        sendCommand('loco-derecha')
    });
    listener.simple_combo('space', function() {
        frena();
    });

//Analytics
(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
    m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
    })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
    ga('create', 'UA-49589151-1', 'no-ip.org');
    ga('send', 'pageview');