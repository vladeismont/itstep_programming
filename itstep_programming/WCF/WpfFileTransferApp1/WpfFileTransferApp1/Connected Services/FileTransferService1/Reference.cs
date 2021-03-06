﻿//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан программой.
//     Исполняемая версия:4.0.30319.42000
//
//     Изменения в этом файле могут привести к неправильной работе и будут потеряны в случае
//     повторной генерации кода.
// </auto-generated>
//------------------------------------------------------------------------------

namespace WpfFileTransferApp1.FileTransferService1 {
    using System.Runtime.Serialization;
    using System;
    
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Runtime.Serialization", "4.0.0.0")]
    [System.Runtime.Serialization.DataContractAttribute(Name="File", Namespace="http://schemas.datacontract.org/2004/07/FileTransferService1")]
    [System.SerializableAttribute()]
    public partial class File : object, System.Runtime.Serialization.IExtensibleDataObject, System.ComponentModel.INotifyPropertyChanged {
        
        [System.NonSerializedAttribute()]
        private System.Runtime.Serialization.ExtensionDataObject extensionDataField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string FileDateField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private long FileLengthField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string FilePathField;
        
        [global::System.ComponentModel.BrowsableAttribute(false)]
        public System.Runtime.Serialization.ExtensionDataObject ExtensionData {
            get {
                return this.extensionDataField;
            }
            set {
                this.extensionDataField = value;
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string FileDate {
            get {
                return this.FileDateField;
            }
            set {
                if ((object.ReferenceEquals(this.FileDateField, value) != true)) {
                    this.FileDateField = value;
                    this.RaisePropertyChanged("FileDate");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public long FileLength {
            get {
                return this.FileLengthField;
            }
            set {
                if ((this.FileLengthField.Equals(value) != true)) {
                    this.FileLengthField = value;
                    this.RaisePropertyChanged("FileLength");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute()]
        public string FilePath {
            get {
                return this.FilePathField;
            }
            set {
                if ((object.ReferenceEquals(this.FilePathField, value) != true)) {
                    this.FilePathField = value;
                    this.RaisePropertyChanged("FilePath");
                }
            }
        }
        
        public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;
        
        protected void RaisePropertyChanged(string propertyName) {
            System.ComponentModel.PropertyChangedEventHandler propertyChanged = this.PropertyChanged;
            if ((propertyChanged != null)) {
                propertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
            }
        }
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="FileTransferService1.IFileTransferService1")]
    public interface IFileTransferService1 {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IFileTransferService1/GetFilesInfo", ReplyAction="http://tempuri.org/IFileTransferService1/GetFilesInfoResponse")]
        WpfFileTransferApp1.FileTransferService1.File[] GetFilesInfo();
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IFileTransferService1/GetFilesInfo", ReplyAction="http://tempuri.org/IFileTransferService1/GetFilesInfoResponse")]
        System.Threading.Tasks.Task<WpfFileTransferApp1.FileTransferService1.File[]> GetFilesInfoAsync();
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IFileTransferService1/GetFileContent", ReplyAction="http://tempuri.org/IFileTransferService1/GetFileContentResponse")]
        byte[] GetFileContent(WpfFileTransferApp1.FileTransferService1.File fileInfo);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IFileTransferService1/GetFileContent", ReplyAction="http://tempuri.org/IFileTransferService1/GetFileContentResponse")]
        System.Threading.Tasks.Task<byte[]> GetFileContentAsync(WpfFileTransferApp1.FileTransferService1.File fileInfo);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IFileTransferService1Channel : WpfFileTransferApp1.FileTransferService1.IFileTransferService1, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class FileTransferService1Client : System.ServiceModel.ClientBase<WpfFileTransferApp1.FileTransferService1.IFileTransferService1>, WpfFileTransferApp1.FileTransferService1.IFileTransferService1 {
        
        public FileTransferService1Client() {
        }
        
        public FileTransferService1Client(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public FileTransferService1Client(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public FileTransferService1Client(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public FileTransferService1Client(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public WpfFileTransferApp1.FileTransferService1.File[] GetFilesInfo() {
            return base.Channel.GetFilesInfo();
        }
        
        public System.Threading.Tasks.Task<WpfFileTransferApp1.FileTransferService1.File[]> GetFilesInfoAsync() {
            return base.Channel.GetFilesInfoAsync();
        }
        
        public byte[] GetFileContent(WpfFileTransferApp1.FileTransferService1.File fileInfo) {
            return base.Channel.GetFileContent(fileInfo);
        }
        
        public System.Threading.Tasks.Task<byte[]> GetFileContentAsync(WpfFileTransferApp1.FileTransferService1.File fileInfo) {
            return base.Channel.GetFileContentAsync(fileInfo);
        }
    }
}
