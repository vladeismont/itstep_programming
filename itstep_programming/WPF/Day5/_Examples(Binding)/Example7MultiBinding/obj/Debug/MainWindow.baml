   M S B A M L   `   `   `  ����O  KExample7MultiBinding, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null;"clr-namespace:Example7MultiBindingExample7MultiBinding  5   
   %    Example7MultiBinding.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   8	converter"clr-namespace:Example7MultiBinding     5   
     � Title$  
MainWindow��5   	   $	��350��6   $	��525��6)    � 	Resources 5      '   !Example7MultiBinding.AddConverter   XAMLResourceAddConverter��%   &	          5   
   6!   5	      .��5      �� .+�5   
   �� $��Число А��6   6$   �� 5   
   -   5        $��TextBox1��5      $��10��6"   $
��10,5q�6,   6<   �� 5   
   $��Число А��6   6$   �� 5   
   -   5        $��TextBox2��5      $��20��6"   $
��10,5q�6,   6<   �� 5   
   -   5        $��textBox3��5      $
��10,5q�6"   .��60   ��5      `� 5       `� 	Converter# [  6    `� Mode$ OneWay=�6U   .1�5      ��  �� ElementName$ TextBox1��6    �� Path$
 Text�65   �� 5      $ TextBox2��6   $
 Text�65   5      .��5      5      5      5      