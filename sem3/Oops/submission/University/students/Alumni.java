package students;

public class Alumni extends StudentDatabase {
    public Alumni(int ID, String Name, String Phone) {
        super(ID, Name, Phone);
    }

    public String getRole() {
        return "Alumni";
    }
}

