   M S B A M L   `   `   `  ����M  IExample7.1DataGrid, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null9!clr-namespace:Example7._1DataGridExample7._1DataGrid  5   	   $    Example7._1DataGrid.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   3local!clr-namespace:Example7._1DataGrid     5   	     � Title$  
MainWindow��5   	   $	��350��6   $	��600��6)   .��5      �  � RowDefinitions 5   
   �� 5	      $��* �6   6)   �� 5
      $
��auto �6   6,   .+�5   
   &   System.Windows.Controls.DataGrid  -   5          Name$ dgMain��5   _      HeadersVisibility$
 None=�6      CanUserAddRows .     AutoGenerateColumns .   �� 
GroupStyle 5      (  "System.Windows.Controls.GroupStyle  5         ContainerStyle 5      �� 5       �� 
TargetType" ��6    .�5      �� 	 �� Property	 � ��
 �� Value
 5   "   �� 5   &    �� 
TargetType" ��66   .R�5   *   9� ��5   .   �� 5   2    �� Orientation$ 
Horizontal=�6=   .+�5   6   �� ��6@   ��  �� Path$
 Name��� 5   6   $�� (��6@   �� 5   6   ��6@   �� $ 	ItemCount��� 5   6   $�� ��6@   �� 5   6   $��Items��6@   �� 5   6   $��)��6@   5   3   .��5   .   �� 5    +   5!   '   5#      5$      5&         Columns 5(      0  *System.Windows.Controls.DataGridTextColumn  5)      1  +System.Windows.Controls.DataGridBoundColumn   Binding 6%   �� *	FirstName+6E     5*       6%   �� *Salory+6B     5+       6%   �� *Date+6@   5-      �� 5.   
   -   5        $��1��5.      $
��50,5q�6   .��6A    Кол-во элементов6S   5/      50      