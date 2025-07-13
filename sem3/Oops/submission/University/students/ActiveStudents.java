package students;

public class ActiveStudents extends StudentDatabase {
    public ActiveStudents(int ID, String Name, String Phone) {
        super(ID, Name, Phone);
    }

    public String getRole() {
        return "Active Students";
    }
}


