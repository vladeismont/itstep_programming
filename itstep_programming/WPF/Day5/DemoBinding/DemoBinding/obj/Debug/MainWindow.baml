   M S B A M L   `   `   `  ����F  BDemoBinding, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null?$clr-namespace:DemoBinding.ConvertersDemoBinding.Converters  5   	       DemoBinding.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   ;
converters$clr-namespace:DemoBinding.Converters     5   	     � Title$  
MainWindow��5   	   $	��350��6   $	��350��6)    � 	Resources 5      .   (DemoBinding.Converters.FontSizeConverter   cFontSizeConverter3   -DemoBinding.Converters.FontSizeImageConverter  cFontSizeImageConverter(  "DemoBinding.Converters.FTconverter 
 FTconv��%W   &	        &	      &	 &       5   
   6'     5   
   6,     5	   
   62   5
      .��5      ��  � DataContext 6   ��  �� ElementName$ 
slFontSize��.+�5   
   �� -   5         ��Name$ 
slFontSize��5       � Value$ 39Q�6%    � Minimum$	 -10Q�60    � Maximum$ 72Q�6>   6M   �� 5   
   -   5         ��Name$ txbText��5      $��.NET WPF��6%   ��5      �� 	 �� Path$	 Value�
 �� Mode$
 TwoWay=��� 5   
    �� Orientation$ 
Horizontal=�6   .+�5      �� -   5        $��25��5      $��5q�6"   6D   �� 5      -   5        $��55��5      $��5q�6"   6D   �� 5      -   5        $��70��5      $��5q�6"   6D   5      �� 5   
   -   5         ��Name$ tbFirst��5      $��5q�6#   60   �� 5   
   -   5        $ tbSecond��5      $��5q�6$   ��5      �� $ tbFirst��$
	 Text� �� UpdateSourceTrigger$ PropertyChanged=�6i   �� 5   
    �� ContentStringFormat$ N2��6/   ��6   �� $	 Value�6/   �� 5   
   ��6   �� $	 Value� �� StringFormat$ {0:N2}���� 5   
   ��6   �� $	 Value� �� 	Converter# [  �� 5   
   $��25��6a   $��25��6l   ��6   �� $	 Value�# [ 6l   �� 5   
   $��5q�6   ��6   �� $	 Value�# [  6j   �� 5   
   -   5         ��Name$
 chbx��5      .��6!   check6(   �� 5   
   -	   5        {�5      �� $
 chbx��$	 	IsChecked�# [ .��6�   
enabled?6�   5      5      