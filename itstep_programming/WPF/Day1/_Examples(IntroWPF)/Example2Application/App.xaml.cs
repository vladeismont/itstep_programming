using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;

namespace Exampl2Application
{
   
    public partial class App : Application
    {
       /* Происходит после вызова метода Application.Run() 
          и непосредственно перед отображением главного окна 
          (если вы передаете главное окно методу Run())
       */   
        private void Application_Startup(object sender, StartupEventArgs e)
        {
            // создание свойства через Application.Current.Properties
            Application.Current.Properties["GlobalValue"] = "Свойство из  Application.Current.Properties";
        }

        /*
         Происходит, когда останавливается приложение  по любой причине.
        */
        private void Application_Exit(object sender, ExitEventArgs e)
        {
            MessageBox.Show("Приложение почти закрыто!");
        }

        /*
         Происходит, когда активизируется одно из окон приложения. Это случается, 
         когда вы переключаетесь с другой программы Windows на это приложение. 
         Также случается при первом показе окна.
         */
        private void Application_Activated(object sender, EventArgs e)
        {
            MessageBox.Show("Приложение активно!!");
        }

       

        /* Происходит при деактивизации окна приложения. Случается, когда 
           вы переключаетесь на другую программу Windows.
         */
        private void Application_Deactivated(object sender, EventArgs e)
        {
            MessageBox.Show("Приложение неактивно!!!");
        }

       /* Происходит, когда возникает необработанное исключение 
          в любом месте приложения (в главном потоке приложения).
       */
        private void Application_DispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
        {
            MessageBox.Show("Исключение " + e.Exception.GetType().ToString() + " отключено");
            // игнорируем exception и продолжаем работу приложения!
            e.Handled=true;
        }
    }
}
