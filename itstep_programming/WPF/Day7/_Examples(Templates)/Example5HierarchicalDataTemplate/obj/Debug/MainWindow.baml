   M S B A M L   `   `   `  ����$   Example5HierarchicalDataTemplate1    +Example5HierarchicalDataTemplate.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	     � Title$  
MainWindow��5   	   $	��350��6   $	��650��6)   $	��350��65   $	��200��6D    � 	Resources 5         TreeTemplate �� ItemsSource �� Path �� Orientation �� Mode��%  &	        �� 5   
    68   �� $ Children�.R�5      �� $ 
Horizontal=�6   .+�5      �� $��3,0,3,0q�65   $��20��6F   $��20��6Q   ��6   �� $
 Logo�6_   �� 5	      
���   ���6   �� $
 Text�$ TwoWay=�6D   5
      5      5      .��5      �  � ColumnDefinitions 5   
   �� 5      $��* �6   $	��150��6)   �� 5      $��* �6   $	��150��6)   .+�5   
   �� 
������$��2q�6*    �� Padding$ 4q�6>   $��5q�6J    �� CornerRadius$ 10��6U   ._�5      R� -   5        	 R�Name$	 tvMain��5      $
��Bold"�6(   $��14(�6:   #��[  5      5      5      �� 5   
   $��1��6   
 � DataContext
 6%   ��  �� ElementName$ tvMain��$ SelectedItem�.+�5      �� $
��10,5q�6   .��6"   Название узла62   �� 5      $
��15,5q�6P   $
��Bold"�6^   ��6   �� *Text+ �� UpdateSourceTrigger$ PropertyChanged=�6r   �� 5      $
��10,5q�6   .��6"   Картинка узла61   �� 5      $	��150��6,   $	��150��68   $
��Left=�6E   $
��15,5q�6`   ��6   �� *Logo+6p   5      5      5       