using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace FileTransferService1
{
    [DataContract]
    public class File
    {
        string _fPath;
        long _fLength;
        string _fDate;
        [DataMember]
        public string FilePath
        {
            get { return _fPath; }
            set { _fPath = value; }
        }
        [DataMember]
        public long FileLength
        {
            get { return _fLength; }
            set { _fLength = value; }
        }
        [DataMember]
        public string FileDate
        {
            get { return _fDate; }
            set { _fDate = value; }
        }
        public File() { }
    }
}
