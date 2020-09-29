document.addEventListener('DOMContentLoaded', function () {
    var butShow = document.getElementById('showHide');
    var divBlock = document.getElementById('vvv');
    var inpEl = document.getElementById('inp');

    butShow.addEventListener('click', function () {

        if( divBlock.classList.contains('hidden') ){
            divBlock.classList.remove('hidden');
        } else {
            divBlock.classList.add('hidden');

        }
    });

    inpEl.addEventListener('keyup', function () {
        console.log( this.value );
    });

    var buts = document.getElementsByClassName('delButton');

    for( var i = 0; i<buts.length; i++ ){
        buts[i].addEventListener('click', function () {
            var d_id = this.getAttribute('data-id');
            var d_tr = document.getElementById(d_id);
            d_tr.remove();
        });
    }

});