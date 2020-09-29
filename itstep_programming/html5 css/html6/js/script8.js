$(document).ready(function () {

   $('.btn').on( 'click', function () {
      if( $(this).data('action') == 'show' ){
         var target = $(this).data('target');
         $(target).show(1000);
      } else {
         var target = $(this).attr('data-target');
         $(target).hide(1000);
      }
   });

   $(document).on('click', '#btn222', function () {
      // $( "#book" ), 5000, function() {
      //    // Animation complete.
      // });

      var elem = '<div style="background-color: #0c5460">1</div><div>2</div>';
      $('#tbl').append(elem);
      $('div').animate({
         backgroundColor: '#ffffff',

      }, 1000, function () {

      })

      clearInterval(timer);
      setTimeout('alert("asfasd")', 1000);
   });


   var timer = setInterval(ttt, 1000);




   function ttt() {
      var dt = new Date();
      var time = dt.getHours() + ":" + dt.getMinutes() + ":" + dt.getSeconds();
      $('#clock').text( time );
   }






});