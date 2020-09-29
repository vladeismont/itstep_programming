$(document).ready(function () {

    $(document).on( 'click', '#load',function () {
    $.ajax('server/get2.txt',{
        data:{},
        success: function(data) {
            $('#tbl').append('<tr><td>'+data+'</td></tr>');
            console.log(data);
        },
        error: function () {
            alert('error');
        }
    });

    } );

});