using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace FileTransferService1
{
    // ПРИМЕЧАНИЕ. Команду "Переименовать" в меню "Рефакторинг" можно использовать для одновременного изменения имени интерфейса "IService1" в коде и файле конфигурации.
    
    [ServiceContract]
    public interface IFileTransferService1
    {
        //[OperationContract]
        //string GetFileRootDir();

        [OperationContract]
        File[] GetFilesInfo();

        [OperationContract]
        byte[] GetFileContent(File fileInfo);
        //[OperationContract]
        //CompositeType GetDataUsingDataContract(CompositeType composite);

        // TODO: Добавьте здесь операции служб
    }

    // Используйте контракт данных, как показано на следующем примере, чтобы добавить сложные типы к сервисным операциям.
    // В проект можно добавлять XSD-файлы. После построения проекта вы можете напрямую использовать в нем определенные типы данных с пространством имен "FileTransferService1.ContractType".
    //[KnownType(typeof(File))]
    //[DataContract]
    //public class File
    //{
    //    string fPath;
    //    long fLength;
    //    string fDate;

    //    [DataMember]
    //    public string FilePath {
    //        get { return fPath; }
    //        set { fPath = value; }
    //    }
    //    [DataMember]
    //    public long FileLength
    //    {
    //        get { return fLength; }
    //        set { fLength = value; }
    //    }
    //    [DataMember]
    //    public string FileDate
    //    {
    //        get { return fDate; }
    //        set { fDate = value; }
    //    }
    //}
    // Используйте контракт данных, как показано на следующем примере, чтобы добавить сложные типы к сервисным операциям.
    // В проект можно добавлять XSD-файлы. После построения проекта вы можете напрямую использовать в нем определенные типы данных с пространством имен "FileTransferService.ContractType".
    //[DataContract]
    //public class CompositeType
    //{
    //    bool boolValue = true;
    //    string stringValue = "Hello ";

    //    [DataMember]
    //    public bool BoolValue
    //    {
    //        get { return boolValue; }
    //        set { boolValue = value; }
    //    }

    //    [DataMember]
    //    public string StringValue
    //    {
    //        get { return stringValue; }
    //        set { stringValue = value; }
    //    }
    //}
}
