   M S B A M L   `   `   `  ����  Example6MultiBinding%    Example6MultiBinding.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	     � Title$  
MainWindow��5   	   $	��250��6   $	��525��6)   .��5      �� $
��Auto=�6   .��5   
   �� .+�5   
   �� -   5        $��sliderFontSize��5      $��10q�6(    � Minimum$ 15Q�64    � Maximum$ 72Q�6A    �� TickFrequency$ 1Q�5       �� TickPlacement$ TopLeft=�6$   6>   �� 5
   
   -   5        $��tbText��5
      $��Пример текста��6    ��5      ��  �� ElementName$ sliderFontSize�� �� Path$ Value� �� Mode$ TwoWay=�6\   �� 5   
   -   5        $��tbMulti��5      $��50,10,50,10q�6#   $
��Bold"�5      ��5      �� $ sliderFontSize��$ Value���5      �� $ tbText��$
 Text���5      �� $ 	btnButton��$ 
Background�5      �� 5   
   -   5        $��	tbComplex��5      $��50,10,50,10q�6#   $
��Bold"�5      $	��120��6&   $
��Left=�62   ��5      �� $ sliderFontSize��$ Value�$ TwoWay=� �� UpdateSourceTrigger$ PropertyChanged=�.��5   M   5      �� 5   
   -   5        	 ��Name$	 	btnButton��5      $��Цвет��6$   
���  ��$��50,10,50,10q�6D   6\   5      5      5      