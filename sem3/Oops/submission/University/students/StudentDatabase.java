package students;



protected class StudentDatabase extends UniversityMemberDatabase {
    public StudentDatabase(int ID, String Name, String Phone) {
        super(ID, Name, Phone);
    }

    public String getRole() {
        return "Student";
    }

    public void addMember() {
        addToMembersList(getName());
    }

    public String getMembers() {
        return getAllMembers();
    }
}