   M S B A M L   `   `   `  ����Q  MExample5ValueConverter, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null?$clr-namespace:Example5ValueConverterExample5ValueConverter  5   	   '    !Example5ValueConverter.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   3my$clr-namespace:Example5ValueConverter     5   	     � Title$  
MainWindow��5      $	��350��6   $	��525��6%    � 	Resources 5      (   "Example5ValueConverter.MyConverter   MyConverter��%   &	          5	   
   6   5
      .��5      ��  � DataContext 6   ��  �� ElementName$ sliderFontSize��.+�5   
   �� -   5        $��sliderFontSize��5      $��10q�6'    � Minimum$ 15Q�63    � Maximum$ 72Q�6@    �� TickFrequency$ 1Q�5       �� TickPlacement$ TopLeft=�6#   6=   �� 5   
   -   5        $��tbText��5      $��Пример текста��6    ��5      ��  �� Path$ Value�64   �� 5   
   $��50,10,50,10q�6n   ��6   �� $ Value�	 �� 	Converter#	 [  
 �� StringFormat$
 {0:C}��6�   �� 5   
   $��50,10,50,10q�6x   ��6   �� $ Value�#	 [  $
 всего {0:C} !!!��6�   �� 5   
    �� ContentStringFormat$ {0:N2}% Completed.��6X   $��50,10,50,10q�6�   ��6   �� $ Value�#	 [  6�   5      5      