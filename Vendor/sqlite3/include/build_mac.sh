echo "Building shell object file."
gcc -c -fPIC shell.c -o ../lib/macOS/shell.o
echo "Building sqlite3 object file."
gcc -c -fPIC sqlite3.c -o ../lib/macOS/sqlite3.o
echo "Building static library libsqlite3.a."
ar rcs ../lib/macOS/libsqlite3.a ../lib/macOS/shell.o ../lib/macOS/sqlite3.o 
echo "Removing object files."
rm -rf ../lib/macOS/*.o
echo "Done."
