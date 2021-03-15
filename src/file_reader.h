
class FileReader {
 public:
   // constructor / destructor
   FileReader(wxWindow *parent, wxWindowID id);
   ~FileReader();

   ReadOptions();
   void WriteOptions();

   ReadHighscore();
   void WriteHighscore();
};
